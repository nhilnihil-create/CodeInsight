#include <bits/stdc++.h>
using namespace std;
typedef vector<long long int> vi;
typedef vector<vi> vvi;
typedef pair<long long int,long long int> ii;
typedef vector<ii> vii;
#define F first
#define S second

int n;


int main(){
    cin >> n;
    int cur = 1;
    string s;
    if (n == 0){
        cout << "0"; return 0;
    }
    while (n != 0){
        //cout << n << " " << cur << endl;
        if (n%2 ){
            s.push_back('1');
            n -= cur;
        }
        else s.push_back('0');
        cur = -cur;
        n /= 2;
    }
    reverse(s.begin(),s.end());
    cout << s;
}
