#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const ll mod = 1e9+7;

double p[301][301][301];
double ev[301][301][301];
main(){
    int n;
    cin>>n;
    int arr[n];
    vi cnt(4);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c = n;c>=0;c--){
        for(int b = n;b>=0;b--){
            for(int a =n;a>=0;a--){
                if(a == 0 && b == 0 && c == 0) {
                   continue;
                }
                if((a+b+c)>n) continue;
                double p_waste = (double)(n-(a+b+c))/n;
                ev[a][b][c]+= ((p_waste)/(1-p_waste) + 1)*(p[a][b][c]);
                
                if(a!=0){
                    double p_go = (double)a/(a+b+c);
                    p[a-1][b][c]+= p[a][b][c]*p_go;
                    ev[a-1][b][c]+= ev[a][b][c]*p_go;
                }
                if(b!=0){
                    double p_go = (double)b/(a+b+c);
                    p[a+1][b-1][c]+= p[a][b][c]*p_go;
                    ev[a+1][b-1][c]+= ev[a][b][c]*p_go;
                }
                if(c!=0){
                    double p_go = (double)c/(a+b+c);
                    p[a][b+1][c-1]+= p[a][b][c]*p_go;
                    ev[a][b+1][c-1]+= ev[a][b][c]*p_go;
                }
            }
        }
    }
    cout<<setprecision(10)<<fixed<<ev[0][0][0];
}