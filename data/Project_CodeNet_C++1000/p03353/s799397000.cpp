#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<string> v;
    int t = min(5, n);

    for (int i = 1; i <= t; i++){ 
        rep(j, n - i + 1){
            v.push_back(s.substr(j, i));
        }
    }

    sort(v.begin(), v.end());

    v.push_back(" ");

    int i = 0, cnt = 1;
    while (true)
{
        if (v[i] != v[i+1])
{
            if (cnt == k)
{
                cout << v[i] << endl;
                break;
            }
            cnt ++;
            i ++;
        }
        else i++;
    }
}
