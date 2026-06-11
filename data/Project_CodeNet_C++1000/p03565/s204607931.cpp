#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
string s, t;
set<string> S;
 
void Work()
{
    int lens = s.size();
    int lent = t.size();
    for(int i = 0; i < lens; i++)
    {
        if(s[i] == '?' || s[i] == t[0])//如果字符相等
        {
            string tmp = s;              //构造判断子串之前的字符
            for(int j = 0; j < i; j++)
                if(tmp[j] == '?')
                    tmp[j] ='a';    
            bool can = false;
            for(int j = 0; j < lent; j++)    //判断是否为子串
            {
 
                if(tmp[i+j]!= '?' && tmp[i+j] != t[j])  //字符匹配
                    break;
                tmp[i+j] = t[j];
                if(j == lent - 1) can = true;
            }
            if(can)
            {
                for(int j = i + lent; j < lens; j++) if(tmp[j] == '?') tmp[j] = 'a';//处理匹配后的字符
                S.insert(tmp);  //压入容器
            }
        }
    }
    if(S.size() == 0) cout << "UNRESTORABLE" << endl;
    else cout << *S.begin() << endl;
}
int main()
{
    cin >> s >> t;
    Work();
}