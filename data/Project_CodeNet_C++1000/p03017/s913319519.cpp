#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    int N;
    cin >> N;
    int A,B,C,D;
    string S;
    cin >> A>>B>>C>>D>>S;
    B--;
    A--;
    C--;
    D--;

    if(C < D){
        for(int i = A;i < C-1;i++){
            if(S[i] == '#' && S[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        for(int i = B;i < D-1;i++){
            if(S[i] == '#' && S[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }           
        }
        cout << "Yes" << endl;
    }
    else{
        for(int i = B;i <= D;i++){
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
}