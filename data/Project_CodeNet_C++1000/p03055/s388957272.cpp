#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> adjlist[n+1];
    bool visited[n+1];
    visited[n] = false;
    for(int i = 1; i < n; i++){
        visited[i] = false;
        int a, b;
        scanf("%d %d", &a, &b);
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    queue<int> tovisit;
    int lvisited;
    tovisit.push(1);
    while(!tovisit.empty()){
        lvisited = tovisit.front();
        visited[lvisited] = true;
        tovisit.pop();
        for(int i = 0; i < adjlist[lvisited].size(); i++){
            if(!visited[adjlist[lvisited][i]]){
                tovisit.push(adjlist[lvisited][i]);
            }
        }
    }
    tovisit.push(lvisited);
    tovisit.push(0);
    int diameter = 1;
    while(tovisit.size() > 1){
        lvisited = tovisit.front();
        visited[lvisited] = false;
        tovisit.pop();
        if(lvisited == 0){
            diameter++;
            tovisit.push(0);
            continue;
        }
        for(int i = 0; i < adjlist[lvisited].size(); i++){
            if(visited[adjlist[lvisited][i]]){
                tovisit.push(adjlist[lvisited][i]);
            }
        }
    }
    if(diameter == 1){
        printf("First");
        return 0;
    }
    if(diameter % 3 == 2){
        printf("Second");
        return 0;
    }
    printf("First");
}
