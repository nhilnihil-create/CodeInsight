#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;
#define rep(i,n) for (int i = 0; i <n; i++) 
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}

using namespace std;
int main(){
    int n,count=0;string a,c,b;std::cin >> n>>a>>b>>c;
    rep(i,n){
        if(a.at(i)==b.at(i)&&b.at(i)==c.at(i)){}
        else if(a.at(i)==b.at(i))count++;
        else if(a.at(i)==c.at(i))count++;
        else if(c.at(i)==b.at(i))count++;
        else count+=2;
    }
    std::cout << count << std::endl;
    
}

