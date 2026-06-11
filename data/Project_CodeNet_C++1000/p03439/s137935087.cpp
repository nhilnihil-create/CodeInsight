#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
  
/*------------------------------------------------------------------*/
int main(void){
    int n; cin >> n;
    int count = 0;
    vector<int> sei(n + 1, -1);
    int num = 0;
    int l = 0;
    int r = n;
    while(count <= 20){
        if(count > 0){
            num = (l + r) / 2;
        }
        cout << num << endl;
        cout.flush();

        string s; cin >> s;

        if(s == "Vacant") return 0; 
        if(s == "Male") sei[num] = 0;
        else sei[num] = 1;

        if(count == 0){
            count++;
            num = n - 1;
            continue;
        }
        
        if((num - l) % 2 == 0){
            if(sei[num] == sei[l]){
                l = num;
            }else{
                r = num;
            }
        }else{
            if(sei[num] == sei[l]){
                r = num;
            }else{
                l = num;
            }
        }
        count++;
    }
}