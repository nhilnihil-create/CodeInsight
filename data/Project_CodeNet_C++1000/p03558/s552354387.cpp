#include<stdio.h>  
#include<algorithm>  
#include<string.h>  
#include<queue>  
using namespace std;  
   
int vis[100009];  
typedef pair<int, int> P;  
   
   
int main()  
{  
    int k;  
    scanf("%d", &k);  
    deque<P> q;  
    memset(vis, 0, sizeof(vis));  
    q.push_back(make_pair(1, 1));  
    while(!q.empty())  
    {  
        P x = q.front(); q.pop_front();  
        if(vis[x.first]) continue;  
        vis[x.first] = 1;  
        if(x.first == 0)  
        {  
            printf("%d\n", x.second);  
            break;  
        }  
        q.push_front(make_pair(x.first*10 % k, x.second));  
        q.push_back(make_pair((x.first+1) % k, x.second+1));  
   
    }  
    return 0;  
}  //看看怎么回事