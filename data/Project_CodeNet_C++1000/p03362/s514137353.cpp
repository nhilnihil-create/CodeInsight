#include <algorithm>
#include <iostream>
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
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007

void Eratosthenes(int n, vector<int> &arr){
    for(int i = 2; i < sqrt(n); i++)
    {
        if(arr[i])
        {
            for(int j = 2; i*j <= n; j++){
                arr[i*j] = 0;
            }
        }
    }
    for(int i = 2; i < n + 1; i++)
    {
        if(arr[i]){
            if(i % 5 != 1) arr[i] = 0; 
        }
    }
}

int main(){
    int N; 
    int cnt = 0;
    cin >> N;
    vector<int> arr(55555, 1);
    Eratosthenes(55555, arr);
    for(int i = 2; i < 55556; i++)
    {
        if(arr[i] == 1 && cnt == N - 1)
        {
            cout << i << endl;
            break;
        }
        if(arr[i] == 1){
            cout << i << ' ';
            cnt++;
        }
    }
}