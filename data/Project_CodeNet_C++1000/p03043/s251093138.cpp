#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(15)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

int main(){
    int n,m,k,cnt=0;

    int tmp;
    double res=0.;
    cin >> n >> k;
    int ptr=n;
    int border = k;
    for(int i=0;i<log2(k)+1;i++){
        tmp = ptr - border;
        if(tmp >= 0){
            res += (double)(tmp+1)/(double)(pow(2,i)*n);
            ptr = border - 1;
        }
        border = (border%2==0?border:border+1)/2;
    }
    cout << DOUBLE <<res << endl;
}