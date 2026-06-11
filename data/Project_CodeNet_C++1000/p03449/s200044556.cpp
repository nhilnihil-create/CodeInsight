#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007

bool vis[200005];
vector<int> vec[2000005], v1;
int child[2000005];
int parent[2000005];
int div1[100005];
int min_indx[200005];
int count1 = 0;
int height = 0;
int max_indx[200005];
void dfs(int node)
{

    vis[node] = 1;

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
int ans[200005];
void fun(int a, int b, int c)
{
    //ll val = 1;

    while (a <= b)
    {
        ans[a] += c;
        int p = -a;
        a += (a & p);
    }
}
int find1(int a)
{
    int sum = 0;
    while (a != 0)
    {
        sum += ans[a];
        int p = -a;
        a -= (a & p);
    }
    return sum;
}
void process2(int A[], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
        M[i][0] = i;
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (find1(M[i][j - 1]) < find1(M[i + (1 << (j - 1))][j - 1]))
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int32_t main()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int sum1[n], sum2[n];
    sum1[0] = arr1[0];
    sum2[0] = arr2[0];
    for (int i = 1; i < n; i++)
    {
        sum1[i] = sum1[i - 1] + arr1[i];
        sum2[i] = sum2[i - 1] + arr2[i];
    }
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum1[i] - sum2[i] + sum2[n - 1] + arr2[i] > max1)
        {
            max1 = sum1[i] - sum2[i] + sum2[n - 1] + arr2[i];
        }
        //   cout << max1 << "\n";
    }
    cout << max1 << "\n";

    return 0;
}