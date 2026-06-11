#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>


using namespace std;
#define INF 1000000005
int main()
{
std::string str;
std::cin >> str;
int l = str.length();
int out = INF;
for(int i = 0; i < l - 1; i++){
    if(str[i] != str[i+1]){
        if(max(i + 1,l - i - 1) < out){
            out = max(i + 1,l - i - 1);
        }
    }
}
if(out == INF){
    std::cout << l << std::endl;
}else {
    std::cout << out << std::endl;
}
return 0;
}