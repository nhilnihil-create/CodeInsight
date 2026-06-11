#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    string num; cin >> num;
    int n = num.size();
    bool nine = true;
    for(int i = 1; i < n; i++){
        if((num[i]-'0') != 9){
            nine = false;
            break;
        }
    }
    if(nine == true) cout << (num[0]-'0')+9*(n-1) << endl;
    else cout << (num[0]-'0')+9*(n-1)-1 << endl;
    return 0;
}
