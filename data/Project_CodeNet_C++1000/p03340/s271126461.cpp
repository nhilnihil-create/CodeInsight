#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    ll res = 0;
    int right = 0;
    int sum = 0;
    for(int left = 0; left < N; left++){
        while(right < N && (sum ^ A[right]) == (sum + A[right])){
            sum += A[right];
            right++;
        }
        res += right - left;
        sum -= A[left];
    }
    cout << res << endl;
}