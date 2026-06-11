#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    for(int i=0; i<=n-2; i++){//Xの最後の文字のite
        map <char,int> table;
        int tmp = 0;
        for(int j=0; j<n; j++){
            if(j <= i){ //前半
                if(!table.count(s[j])){
                    table[s[j]] = 1;
                }
            }
            else{       //後半
                if(table.count(s[j])){
                    if(table.at(s[j]) == 1){
                        tmp ++;
                        table.at(s[j])++;
                        
                    }
                }
            }
        if(ans < tmp){
            ans = tmp;
        }
        }
    }

    cout << ans << endl;

}