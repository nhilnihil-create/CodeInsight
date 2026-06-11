#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int, int>> fVec, tVec;
vector<int> dirVec[2];
int e[5], memo[8001][16004], result[5];
char s[8005];

void func(int dir, int tidx, int hap, int fidx)
{
    if(result[dir] == 1)
    {
        return;
    }
    if(tidx == dirVec[dir].size())
    {
        if(hap == e[dir])
        {
            result[dir] = 1;
        }
        return;
    }
    int &ret = memo[tidx][hap + 8001];
    if(ret != 0)
    {
        return;
    }
    ret = 1;
    int nextHap = 0;
    for(int i = fidx; i < fVec.size(); i++)
    {
        if(fVec[i].first > dirVec[dir][tidx])
        {
            nextHap = fVec[i].second;
            fidx = i;
            break;
        }
    }
    func(dir, tidx + 1, hap + nextHap, fidx + 1); 
    func(dir, tidx + 1, hap - nextHap, fidx + 1);
    return;
}

int main()
{
    int length;
    scanf("%s %d %d", s, &e[0], &e[1]);
    length = strlen(s);
    int count = 1;
    for(int i = 0; i < length; i++)
    {
        if(s[i] != s[i + 1])
        {
            if(s[i] == 'T')
            {
                tVec.push_back({i, count});
            }
            else
            {
                fVec.push_back({i, count});
            }
            count = 0;
        }
        count++;
    }
    if(tVec.size() == 0)
    {
        if(e[1] == 0 && fVec[0].second == e[0])
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
        return 0;
    }
    if(fVec.size() == 0)
    {
        if(e[0] == 0 && e[1] == 0)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
        return 0;
    }
    int flag = 0;
    for(int i = 0; i < tVec.size(); i++)
    {
        if(tVec[i].second % 2 != 0)
        {
            flag = !flag;
        }
        dirVec[flag].push_back(tVec[i].first);
    }
    int startHap = 0, startF = 0;
    if(fVec[0].first < tVec[0].first)
    {
        startHap = fVec[0].second;
        startF = 1;
    }
    func(0, 0, startHap, startF);
    memset(memo, 0, sizeof memo);
    func(1, 0, 0, 0);
    result[0] + result[1] == 2 ? printf("Yes") : printf("No");
}