#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n;
deque<int> qu, ql;
bool a[100005];

int main()
{
    scanf("%d", &n);
    qu.push_back(1);
    ql.push_back(1);
    while(!qu.empty())
    {
        int t1 = qu.front();
        int t2 = ql.front();
        qu.pop_front();
        ql.pop_front();
        if(t1 == 0)
        {
            printf("%d", t2);
            return 0;
        }
        if(a[t1]) continue;
        a[t1] = true;
        qu.push_front(t1 * 10 % n);
        ql.push_front(t2);
        qu.push_back((t1 + 1) % n);
        ql.push_back(t2 + 1);
    }
    return 0;
}
