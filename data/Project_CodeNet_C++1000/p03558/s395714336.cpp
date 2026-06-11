#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int k;
int cost[100000];

deque<int> deq;

int main(){
    cin >> k;
    fill(cost, cost + k, k * 10);
    deq.push_back(1);
    cost[1] = 0;
    while(!deq.empty()){
        int x = deq.front();
        // cout << x << endl;
        deq.pop_front();
        int cur = cost[x];
        int next0 = (x * 10) % k;
        int next1 = (x + 1) % k;
        if (cost[next0] > cur) {
            cost[next0] = cur;
            deq.push_front(next0);
        }
        if (cost[next1] > cur + 1) {
            cost[next1] = cur + 1;
            deq.push_back(next1);
        }
    }
    cout << cost[0] + 1<< endl;
}
