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

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main()
{
     int H,W;
     cin >> H >> W;
     vector<vector<char>> C(H,vector<char> (W));
     for (int i = 0; i < H;i++)
     {
         for (int j = 0; j < W;j++)
         {
             cin >> C[i][j];
         }
     }
     bool ok = true;
     bool Co = false;
     for (int i = 0; i < H; i++)
     {
         for (int j = 0; j < W;j++)
        {
            Co = false;
            for (int x = 0; x < 4; x++)
            {
                if(C[i][j] == '#'){
                    if (i + dx[x] >= 0 && j + dy[x] >= 0 && i + dx[x] < H && j + dy[x] < W)
                    {
                        if(C[i+dx[x]][j+dy[x]] == '#')
                        {
                            Co = true;
                        }
                    }
                }
                else{
                    Co = ok;
                    break;
                }
            }
            if(Co == false){
                ok = false;
                //cout << i <<":"<< j << endl;
            }
         }
     }
     if(ok){
         cout << "Yes" << endl;
     }
     else{
         cout << "No" << endl;
     }
}
