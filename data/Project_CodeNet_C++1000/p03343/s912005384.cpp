#include<bits/stdc++.h>
using namespace std;

int N, K, Q;
int A[2010];

bool judge(int mid)
{
    //printf("mid : %d\n", mid);

    int mem[2010] = {0};
    for(int i = 0; i < N; i++)
    {
        memset(mem, 0, sizeof(mem));
        //printf(" bottom : %d\n",A[i]);
        for(int j = 0; j < N; j++)
        {
            if(A[j] < A[i])mem[j] = 2;
            else if(A[j] <= A[i] + mid)mem[j] = 1;
            else mem[j] = 0;
        }

        /*
        printf("  mem : ");
        for(int j = 0; j < N; j++)printf("%d ",mem[j]);printf("\n");
        */

        int q = 0;
        int cnt = 0, len = 0;
        for(int j = 0; j <= N; j++)
        {
            if(j == N || mem[j] == 2)
            {
                q += max(min(len - K + 1, cnt), 0);
                cnt = len = 0;
            }
            else
            {
                if(mem[j] == 1)cnt++;
                len++;
            }
        }

        //printf("  q : %d\n",q);

        if(q >= Q)return true;
    }

    return false;
}

int main()
{
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++)cin >> A[i];

    int l = 0, r = 1000000001;
    for(int i = 0; i < 50; i++)
    {
        int mid = (l + r) / 2;
        if(judge(mid))r = mid;
        else l = mid;
    }

    cout << r << endl;
    return 0;
}
