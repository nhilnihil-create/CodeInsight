#include<iostream>
#include<algorithm>

using namespace std;

long long child[105];

int main(){
    int N;
    long long x;
    cin >> N >> x;
    for(int i=1; i<=N; i++){
        cin >> child[i];
    }
    sort(child+1, child+N+1);
    if(x < child[1]){
        cout << "0" << endl;
     } else {
        int temp = 0;
        while(x >= child[temp+1] && temp < N){
            temp++;
            x-= child[temp];
        }
        if(x != 0 && temp == N) temp --;
        cout << temp  << endl;
     }
}