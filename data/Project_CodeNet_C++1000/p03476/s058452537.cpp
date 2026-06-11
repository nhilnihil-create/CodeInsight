#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main()
{
    vector<int> p(100005), l(100005);
    queue<int> q, d;
    d.push(2);

    int x;
    p[1] = 0;
    p[2] = 1;
    for(int i=3; i<100005; i++){
        q = d;
        while(!q.empty()){
            x = q.front();
            q.pop();
            if(i%x == 0){
                p[i] = p[i-1];
                break;
            }
            if(q.empty()){
                p[i] = p[i-1] + 1;
                d.push(i);
            }
        }
    }

    l[0] = 0;
    l[1] = 0;
    l[2] = 0;
    for(int i=3; i<100005; i++){
        if(p[i] > p[i-1] && p[(i+1)/2] > p[(i-1)/2])    l[i] = l[i-1] + 1;
        else    l[i] = l[i-1];
    }

    int Q, a, b;    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> a >> b;
        cout << l[b] - l[a-1] << endl;
    }
    return 0;
}