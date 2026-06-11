#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);
struct node
{
    string city;
    int id;
    int score;
};
node a[105];
bool cmp(node a, node b)
{
    if(a.city == b.city)
    {
        return a.score > b.score;
    }
    return a.city < b.city;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].city >> a[i].score;
        a[i].id = i;
    }
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout << a[i].id + 1 << endl;
    }
    return 0;
}