    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ld = long double;
    #define rep(i, n) for (int i = 0; i < (int)(n); i++)
    #define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
    // vector<vector<int>> A(3, vector<int>(4));
    int main() {
        int A,B;
        cin>>A>>B;
        string S;
        cin>>S;
        bool ans=true;
        rep(i,A+B+1){
            if(i!=A){
                if(48<=int(S[i])&&int(S[i])<=57){
                }
                else{
                    ans=false;
                    break;
                }
            }
            else{
                if(S[i]!='-'){
                    ans=false;
                    break;
                }
            }
        }
        if(ans==true){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }