#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

const int N = 55556;

bool st[N];
int primes[N], cnt;
vector<int> nums;

void init(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])  primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0)  break;
        }
    }
    for(int i = 21; i < N; i += 10)
        if(!st[i])  nums.push_back(i);
}

int main()
{
    init(N - 1);
    
    int n;
    scanf("%d", &n);
        
    for(int i = 0; i < n; i ++)  printf("%d ", nums[i]);
    return 0;
}