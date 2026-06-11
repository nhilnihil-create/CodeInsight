#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    int tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    int r; 
    r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    vector<int>a(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int>l(n+1);
    vector<int>r(n+1);

    l[1] = a[1];
    r[n] = a[n];
    for(int i = 2; i <= n-1; i++){
        l[i] = gcd(l[i-1],a[i]);
    }
    for(int i = n-1; i >= 1; i--){
        r[i] = gcd(r[i+1],a[i]);
    }

    int result = max(l[n-1],r[2]);//両端を入れないやつをまず最初に見る///
    for(int i = 2; i < n; i++){
        result = max(result,gcd(l[i-1],r[i+1]));
    }

    cout << result << endl;
}