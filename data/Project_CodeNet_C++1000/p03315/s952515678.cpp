using namespace std;
#include <bits/stdc++.h>
#include<math.h>
int main()
{
    int a=0;
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'){
            a++;
        }
        else if(s[i]=='-'){
            a--;
        }
    }
    std::cout << a << std::endl;
}
