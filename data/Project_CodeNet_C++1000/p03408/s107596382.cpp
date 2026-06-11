#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; i++)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; i--)
#define vi vector<int>
#define vs vector<string>
#define all(x) (x).begin(),(x).end()
int main() {
    int n,m;

    cin >> n;
    vs s(n);
    repp(i,0,n){
        cin >> s[i];
    }

    cin>> m;
    vs t(m);
    repp(i,0,m){
        cin >> t[i];
    }

    vi cnt(n+1,0);
    repp(i,0,n){
        repp(j,0,n){
            if(s[i]==s[j]){
                cnt[i]++;
            }
        }
        repp(j,0,m){
            if(s[i]==t[j]){
                cnt[i]--;
            }
        }
    }
    cout<< *max_element(all(cnt)) <<endl;
}