#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
#include <list>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 1400
#define LARGENUM 1000000007
#define INF 9223372036854775807
#define ull unsigned long long 
typedef pair <ull, int> P;

int M[MAX][MAX], Vertical[MAX][MAX], Horizontal[MAX][MAX];

int main(){
    int N, H, a, b, count = 0;
    ull total = 0;
    list <int> A, B;
    cin >> N >> H;
    rep(i, N){
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    A.sort();
    auto it = A.end();
    it --;
    a = *it;
    B.sort();
    B.reverse();
    while (total < H){
        if (B.empty() || a >= *B.begin()){
            count += (H - total) / a;
            if ((H - total) % a != 0) count++;
            break;
        }
        else {
            total += *B.begin();
            B.pop_front();
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
