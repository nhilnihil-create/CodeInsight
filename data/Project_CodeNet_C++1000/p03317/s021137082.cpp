#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int tmp=k, cnt=1;
    if(n<=tmp){
        cout << cnt << endl;
        return 0;
    }
    while(true){
        tmp = tmp+k-1;
        cnt++;
        if(n<=tmp) break;
    }
    cout << cnt << endl;
    return 0;
}