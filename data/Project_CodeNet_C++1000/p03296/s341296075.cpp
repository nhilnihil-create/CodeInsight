#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int count = 0;
    int prei = a[0];
    for(int i=1;i<N;i++){
        if(prei == a[i]){
            if(prei == a[i+1]) i++;
            count++;
        }
        prei = a[i];
    }
    cout << count << endl;

    return 0;
}