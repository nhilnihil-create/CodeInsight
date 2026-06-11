#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 10e17;
#define mod 1000000007

bool vis[200005];
vector<int> vec[2000005], v1;
int child[2000005];
int parent[2000005];
int div1[100005];
int min_indx[900005];
int count1 = 0;
int height = 0;
int max_indx[200005];
void dfs(int node)
{

    vis[node] = 1;
    // cout << node << "\n";
    min_indx[count1] = node;
    max_indx[node] = min(max_indx[node], count1);
    count1++;

    //  count1++;
    child[node] = height++;
    for (int i = 0; i < vec[node].size(); i++)
    {
        if (!vis[vec[node][i]])
        {
            dfs(vec[node][i]);
            min_indx[count1] = node;
            max_indx[node] = min(max_indx[node], count1);
            count1++;
        }
    }
    height--;
}

int MAXN = 200005;
int LOGMAXN = (int)log2(200005) + 1;
int M[200005][60];
void process2(int A[], int N)
{
    int i, j;

    //initialize M for the intervals with length 1
    for (i = 0; i < N; i++)
        M[i][0] = i;
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
//int parent[200005];
vector<int> vec1;
//bool vis[200005];
//int hei[200005];
int lev[200005];
int dis[200005];
bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.second < b.second;
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //  int t;
    int n;
    cin >> n;
    int x1 = 0, y1 = 0;
    int t1 = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        int p1 = fabs(x - x1);
        int p2 = fabs(y - y1);
        int p3 = t - t1;
        if (p3 < p1 + p2)
        {
            flag = 1;
           // cout << "tree"
             //    << "\n";
        }
        else
        {
            if ((p3 - p1 - p2) % 2)
                flag = 1;
        }
        x1 = x;
        y1 = y;
        t1 = t;
       // cout << flag << "\n";
    }
    if (flag)
        cout << "No"
             << "\n";
    else
    {
        cout << "Yes"
             << "\n";
    }

    return 0;
}
