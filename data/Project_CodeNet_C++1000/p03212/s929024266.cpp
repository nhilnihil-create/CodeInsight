#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N;
void input()
{
    cin >> N;
}

bool check(int n)
{
    if(n > N || n < 1) return false;
    bool three = false, five = false, seven = false;
    while(n > 0){
        switch (n%10){
        case 3:
            three = true;
            break;
        case 5:
            five = true;
            break;
        case 7:
            seven = true;
        default:
            break;
        }
        n /= 10;
    }

    if(three && five && seven) return true;
    else return false;
}

void add753(string S, int& ans)
{
    if(S.length() > 9){
        return;
    }
    int num = 0;
    for(int i=0; i<S.length(); ++i){
        num = num * 10 + S[i] - '0';
    }
    if(check(num)) ++ans;

    add753(S+'3',ans);
    add753(S+'5',ans);
    add753(S+'7',ans);
}

void solve()
{
    string S = "";
    int ans = 0;
    add753(S,ans);
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}