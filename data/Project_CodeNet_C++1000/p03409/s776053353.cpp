#include<cstdio>
#include<set>
#include<functional>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    unsigned N;
    scanf("%u", &N);
    pair<unsigned, unsigned> red[N];
    set<pair<unsigned, unsigned> > blue;
    unsigned a, b;
    for(int i = 0; i < N; ++i){
        scanf("%u %u", &red[i].first, &red[i].second);
    }
    sort(red, red + N, greater<pair<unsigned, unsigned> >());
    unsigned c, d;
    for(int i = 0; i < N; ++i){
        scanf("%u %u", &c, &d);
        blue.emplace(d, c);
    }
    unsigned answer = 0;
    for(auto i : red){
        for(auto j : blue){
            if(j.second > i.first && j.first > i.second){
                answer++;
                blue.erase(j);
                break;
            }
        }
    }
    printf("%u\n", answer);
	return 0;
}