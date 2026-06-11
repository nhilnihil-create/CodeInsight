#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N,d[100];
    int tmp;
    set<int> v;

    cin >> N;

    for(int i = 0;i < N;i++){
        cin >> tmp;
        v.insert(tmp);
    }

    cout << v.size() << endl;

    return 0;
}