#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
    string s;
    cin >> s;
    int n = s.size() - 1;
    for (int bit = 0; bit < (1 << n); ++bit) {
        string S = s;
        for (int i = 0; i < n; i++) {
            int g = 2 * (i + 1) - 1;
            if (bit & (1 << i)) {
                S.insert(g, "+");
            } else {
                S.insert(g, "-");
            }
        }
        int count=0;
        bool flag=true;
        for(int i=0;i<S.size();i++){
            if(S[i]=='+'){
                flag=true;
            }else if(S[i]=='-'){
                flag=false;
            }else
            {
                if(flag){
                    count+=S[i]-'0';
                }else
                {
                    count-=S[i]-'0';
                }
                
            }
        }
        if(count==7){
            cout<<S<<"=7"<<endl;
            return 0;
        }
    }
    return 0;
}
