#include <bits/stdc++.h>
using namespace std;
char in[120];
pair<pair<string,int>,int> p[110];

int main(){
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        int t;
        scanf("%s%d", in, &t);
        string tmp = in;
        p[i] = make_pair(make_pair(in,-t),i);
    }
    std::sort(p,p+a);
    for(int i = 0; i < a; i++)
    cout << p[i].second + 1 << endl;
    return 0;
}
