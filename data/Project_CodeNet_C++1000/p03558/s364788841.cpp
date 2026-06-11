#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 10000000;

int main()
{
    int k;
    cin >> k;
    while(k % 2 == 0) k /= 2;
    while(k % 5 == 0) k /= 5;
    int a[100002]; //kで割った余りがiとなる最小の和
    fill(a, a + k, INF);
    a[1] = 1;
    queue<int> que;
    que.push(1);
    while(que.size()){
        int now = que.front();
        que.pop();
        int next = now * 10 % k;
        int count = 0;
        while(a[next] > a[now]){
            a[next] = a[now];
            count++;
            next = next * 10 % k;
        }
        if(a[now] + 1 < a[(now + 1) % k]){
            a[(now + 1) % k] = a[now] + 1;
            que.push((now + 1) % k);
        }
        next = now * 10 % k;
        for(int i = 0; i < count; i++){
            if(a[next] + 1 < a[(next + 1) % k]){
                a[(next + 1) % k] = a[next] + 1;
                que.push((next + 1) % k);
            }
            next = next * 10 % k;
        }
    }
    cout << a[0] << endl;
}