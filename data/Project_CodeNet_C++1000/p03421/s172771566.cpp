#include<iostream>
using namespace std;
typedef long long LL;
const int N = 3e5;
LL boxes[N+1];
LL ans[N+1];
int main()
{
    LL n, a, b; cin >> n >> a >> b;
    if(!(a+b-1 <= n && n <= a*b))
        cout<<-1<<endl;
    else
    {
        boxes[a-1] = b;
        for(int i = 0; i < a-1; i++)
            boxes[i] = 1;

        for(int total = a+b-1, i = 0; total < n; total++, i = (i+1)%(a-1))
            boxes[i]++;

        int ctr = 0;
        for(int j = 0; j < a; j++)
        {
            for(int t = 0; t < boxes[j]; t++)
                ans[ctr+boxes[j]-t] = ctr+t;
            ctr += boxes[j];
        }
        for(int i = 1; i <= n; i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}