#include<bits/stdc++.h>
using namespace std;

int main (){
    int a,b,c;
    cin >>a>>b>>c;
    vector<int> s(3);
    int tmp,i,j;
    s.at(0) = abs(a-b);
    s.at(1) = abs(b-c);
    s.at(2) = abs(c-a);
    for(i=0;i<3;i++){
        for(j=1;j<3-i;j++){
            if(s.at(i)<s.at(i+j)){
                tmp = s.at(i);
                s.at(i) = s.at(i+j);
                s.at(i+j) = tmp;
            }
        }
    }
    cout << s.at(1)+s.at(2) <<endl;

    return 0;
}