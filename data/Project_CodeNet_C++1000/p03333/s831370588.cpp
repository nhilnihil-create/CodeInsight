#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l1[n], r1[n], l2[n], r2[n];
    for(int i = 0; i < n; i++){
        cin >> l1[i] >> r1[i];
        l2[i] = l1[i];
        r2[i] = r1[i];
    }
    sort(r1, r1+n);
    sort(l1, l1+n);
    int houkou;
    int left = 0;
    int right = 0;
    long long int sum1 = 0;
    long long int sum2 = 0;
    houkou = 0;
    int x = 0;
    /*0はleft*/
    if(n == 1 && l1[0] <= 0 && r1[0] >= 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(houkou == 0){
            if(l1[n-1-left]-x >= 0) {
                sum1 += l1[n-1-left]-x;
                x = l1[n-1-left];
            }
            left++;
        }
        else{
            if(x-r1[right] >= 0){
                sum1 += x-r1[right];
                x = r1[right];
            }
            right++;
        }
        if(houkou == 0)houkou = 1;
        else houkou = 0;
        if(i == n-1) sum1 += abs(x);
    }
    houkou = 1;
    x = 0;
    right = 0;
    left = 0;
    for(int i = 0; i < n; i++){
        if(houkou == 0){
            if(l1[n-1-left]-x >= 0){
            sum2 += l1[n-1-left]-x;
            x = l1[n-1-left];
            }
            left++;
        }
        else{
            if(x-r1[right] >= 0){
            sum2 += x-r1[right];
            x = r1[right];
            }
            right++;
        }
        if(houkou == 0)houkou = 1;
        else houkou = 0;
        if(i == n-1) sum2 += abs(x);
    }
    long long int sum;
    if(sum1 > sum2) sum = sum1;
    else sum = sum2;
    cout << sum << endl;
    return 0;
}