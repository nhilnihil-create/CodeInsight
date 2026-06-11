    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main(){
    int a, b, c, d, f;
    cin >> a >> b >> c >> d;
    int e = min(min(min(a, b), c), d);
    if(e == a){
        f = min(min(b, c), d);
    }
    else if(e == b){
        f = min(min(a, c), d);
    }
    else if(e == c){
        f = min(min(a, b), d);
    }
    else if(e == d){
        f = min(min(a, b), c);
    }
    int g = max(max(max(a, b), c), d), h;
    if(g == a){
        h = max(max(b, c), d);
    }
    else if(g == b){
        h = max(max(a, c), d);
    }
    else if(g == c){
        h = max(max(a, b), d);
    }
    else if(g == d){
        h = max(max(a, b), c);
    }
    if(e == 1 && f == 4 && h == 7 && g == 9){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
    }
