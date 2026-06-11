#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; 
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int res = 0;
    while(1){
        //for each height
        if(*max_element(ALL(h)) == 0) break;
        int i = 0;
        while(i < n){
            if(h[i] == 0) i++;
            else{
                res++;
                while(i < n && h[i] > 0){
                    --h[i];
                    i++;
                }
            }
        }
    }
    cout << res << endl;
}