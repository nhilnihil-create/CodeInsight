#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int N;
vector<int> march(5, 0);
ll ans = 0;

void dfs(vector<int> &A){
    if(A.size() == 3){
        ll tmp = 1;
        for(int i : A){
            tmp *= march[i];
        }
        ans += tmp;
        return;
    }

    int a;
    if(A.size() == 0) a = 0;
    else a = A.back() + 1;

    while(a <= 4){
        A.push_back(a);
        dfs(A);
        A.pop_back();
        a++;
    }
}


int main(){
    cin >> N;
    rep(i, N){
        string s;
        cin >> s;
        if(s[0] == 'M') march[0]++;
        else if(s[0] == 'A') march[1]++;
        else if(s[0] == 'R') march[2]++;
        else if(s[0] == 'C') march[3]++;
        else if(s[0] == 'H') march[4]++;
    }

    vector<int> A(0);
    dfs(A);

    cout << ans << endl;

}