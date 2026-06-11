#include<bits/stdc++.h>
using namespace std;

int bitsum(int n){
    int sum=0;
    int dis;
    sum += n/10000; dis = n%10000;
    sum += dis/1000; dis = dis%1000;
    sum += dis/100; dis = dis%100;
    sum += dis/10; dis = dis%10;
    sum += dis;
    return sum;
}

int main(){

    int n, a, b;
    int sum=0;
    int dispose;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++){
        dispose = bitsum(i);
        if(dispose>=a && dispose<=b)
            sum += i;
    }
    cout << sum << endl;
}