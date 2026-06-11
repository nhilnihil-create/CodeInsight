#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
using namespace std;
typedef	long long int ll;

int main(){
    int n;
    cin >> n;
    if(n==3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
    if(n==4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }
    if(n==5){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << " " << 60 << endl;
        return 0;
    }
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(63);
    v.push_back(20);
    long long int sum = 90;
    int i = 4;
    int num = 64;
    while(1){
        if(i>=n-2) break;
        if(num%2 == 0 || num%3 == 0 || num%5 == 0){
            v.push_back(num);
            sum += num;
            i++;
        }
        num++;
    }
    if(sum%2 == 1){
        sum += 3;
        v.push_back(3);
    }
    else{
        sum += 4;
        v.push_back(4);
    }
    int s = sum%30;
    if(s == 10){
        v.push_back(50);
        sum += 50;
    }
    else if(s == 0){
        v.push_back(30);
        sum += 30;
    }
    else if(s == 28){
        v.push_back(32);
        sum += 32;
    }
    else if(s == 26){
        v.push_back(34);
        sum += 34;
    }
    else{
        v.push_back(30-s);
        sum += 30-s;
    }
    for(int j = 0; j < n; j++){
        cout << v[j] << " ";
    }
    cout << endl;
    return 0;
}