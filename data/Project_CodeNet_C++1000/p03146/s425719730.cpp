#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s;
    cin >> s;

    int cnt=1;
    int a=s;
    map<int,int> check;
    while(check[a]!=1){
        check[a]=1;
        if(a%2==0) a=a/2;
        else a=3*a+1;
        cnt++;
    }
    cout << cnt << endl;
}
