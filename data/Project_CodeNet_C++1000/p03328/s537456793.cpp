#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int temp=b-a;
    int sum=0;
    for(int i=1; i<temp; i++){
       sum+=i;
    }
    cout << sum-a << endl;
    return 0;
}