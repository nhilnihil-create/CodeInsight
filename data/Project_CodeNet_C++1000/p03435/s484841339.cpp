#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> c(3,vector<int>(3));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c.at(i).at(j);
        }
    }

    bool tf = true;

    vector<int> a(3),b(3);
    a.at(0)=0;
    b.at(1)=c.at(0).at(1)-a.at(0);
    b.at(2)=c.at(0).at(2)-a.at(0);
    b.at(0)=c.at(0).at(0)-a.at(0);
    a.at(1)=c.at(1).at(0)-b.at(0);
    a.at(2)=c.at(2).at(0)-b.at(0);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(c.at(i).at(j)!=a.at(i)+b.at(j)){
                tf = false;
            }
        }
    }

    if(tf==true)cout << "Yes" <<endl;
    else cout << "No" << endl;
}