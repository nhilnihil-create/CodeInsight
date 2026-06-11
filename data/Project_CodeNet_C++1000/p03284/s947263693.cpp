    #include <bits/stdc++.h>
    using namespace std;
    int main() {

    int x,y;
    cin>>x>>y;
    int min=x/y;
    int mx=(x%y!=0?x/y+1:x/y);
    cout<<mx-min;


    }
