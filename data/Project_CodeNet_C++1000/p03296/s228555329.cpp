#include <iostream>

using namespace std;

#define MAXN 100
int a[MAXN];
int N;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int count = 0;
    for(int i=0;i<N-1;i++){
        if(a[i]==a[i+1]){
            count++;
            a[i+1] = -1;
        }
    }
    cout << count << endl;
    return 0;
}