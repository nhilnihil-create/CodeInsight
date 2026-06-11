#include <bits/stdc++.h>
using namespace std;

int A[100005], B[100005], BIT[100005];
map<int, int> M;

void update(int i)
{
    for(; i<=100000; i+= (i&(-i)))
        BIT[i]++;
}

int query(int i)
{
    int ans = 0;
    
    for(; i>0; i-= (i&(-i)))
        ans += BIT[i];
    
    return ans;
}

long long func(int N, int K)
{
    for(int i=1; i<=N; i++)
    {
        if(A[i] <= K)
            B[i] = -1;
        else
            B[i] = 1;
    }
    
    M.clear();
    memset(BIT, 0, sizeof(BIT));
    
    M[0];
    
    int k = 0;
    long long ans = 0;
    
    for(int i=1; i<=N; i++)
    {
        B[i] += B[i-1];
        M[ B[i] ];
    }
    
    for(auto &it : M)
        it.second = ++k;
    
    update(M[0]);
    
    for(int i=1; i<=N; i++)
    {
        ans += i - query(M[ B[i] ]);
        update(M[ B[i] ]);
    }
    
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++)
        cin >> A[i];
    
    int left = 1, right = (int)1e9, ans = 0;
    long long subarrays = (long long) N * (N+1) / 2;
    
    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(func(N, mid) >= (subarrays+2)/2)
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    
    cout << ans << "\n";
    return 0;
}