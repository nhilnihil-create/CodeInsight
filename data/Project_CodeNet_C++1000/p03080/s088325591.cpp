#include <iostream>
#include <string>
#include <algorithm>
using namespace std;int main(){int n;string s;cin>>n>>s;if(count(s.begin(),s.end(),'R')>n/2)cout<<"Yes"<<endl;else cout<<"No"<<endl;return 0;}
