#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N, x, count = 0;
    cin >> N >> x;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < N; i++){
        if(x < a[i] || (x > a[i] && i == N - 1)) break;
        x -= a[i];
        count++;
    }
    cout << count << endl;
}