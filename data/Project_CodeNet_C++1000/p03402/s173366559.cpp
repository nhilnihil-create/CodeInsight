#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    A--; B--;
    vector<string> res(100, string(50, '.') + string(50, '#'));
    int i=0;
    int j=0;
    while(B>0){
        res[i][j] = '#';
        B--;
        if(j==48){ j=0; i+=2;}
        else     { j+=2;}
    }
    i=0;
    j=51;
    while(A>0){
        res[i][j] = '.';
        A--;
        if(j==99){ j=51; i+=2;}
        else     { j+=2;}
    }

    cout << "100 100" << endl;
    for(auto s : res) cout << s << endl;

    return 0;
}