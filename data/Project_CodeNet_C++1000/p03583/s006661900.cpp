#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(x) x.begin(),x.end()
#define ld long double
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
signed main(){
    fast;
    int N;
    cin>>N;
    for(int w = 1;w<=3500;w++){
        for(int h = 1;h<=3500;h++){
            int num = N*w*h;
            int den = (int)4*w*h - N*(w+h);
            if(den>0){
                if(num%den == 0 && (num/den)<=3500){
                    cout<<h<<" "<<num/den<<" "<<w;
                    return 0;
                }
            }
        }
    }
}