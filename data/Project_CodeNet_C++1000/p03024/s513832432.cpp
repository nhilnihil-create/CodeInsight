#include <bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin >> s;

int counto = 0;
int count = 0;

for(int i=0;i < s.size();i++){
    if (s.at(i) == 'o'){
        counto++;
    }
}

int num = 15-s.size();

if((num+counto) >= 8){
    cout << "YES" << endl;
}else{
    cout << "NO" << endl;
}

return 0;
}