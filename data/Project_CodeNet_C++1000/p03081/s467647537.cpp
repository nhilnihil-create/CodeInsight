#include<iostream>
#include<fstream>
#include<cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n, q;
string sir;
int verif(int a, int b, vector<char>&x, vector<char>&y, string &s)
{
    int i;
    int sz = x.size();
    for(i = 0; i < sz; i++)
    {
        if(x[i] == s[a])
        {
            if(y[i] == 'L')
               a = a  -1;
            else a = a +  1;
        }
        if(s[a] == '_')
            if(a == b)
                return 1;
    }
    return 0;
}
int main()
{
    int golem;
cin >> n >> q;
cin >> sir;
sir = "_" + sir + "_";
golem = n;

vector<char>v(q);
vector<vector<char>> w(2, vector<char>(q));

for(int i = 0; i <= q - 1; i++)
{
    cin >> v[i];
    cin >> w[0][i];
    if(w[0][i] == 'L')
        w[1][i] = 'R';
    else w[1][i] = 'L';
}
for(int i = 0; i < 2; i++)
{
    int Left = 0;
    int Right = n + 1;
    while(Right - Left > 1)
    {
        int mid = (Left + Right) / 2;
        if(verif(mid, 0, v, w[i], sir) )
            Left = mid;
        else Right = mid;
    }
    golem = golem - Left;

    reverse(sir.begin(), sir.end());
}
cout << golem;

}