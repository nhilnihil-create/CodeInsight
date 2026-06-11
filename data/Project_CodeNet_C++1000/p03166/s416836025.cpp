#include <bits/stdc++.h>

using namespace std;


void traverse(vector<int>& distances,vector<vector<int> >& adjList,vector<bool>& visited, int node){
    visited[node] = true;
    for(int i=0;i<adjList[node].size();i++){
      if(!visited[adjList[node][i]])
        traverse(distances,adjList,visited,adjList[node][i]);
       distances[node] = max(distances[node],1+distances[adjList[node][i]]);

    }
}

int main(){
  int N,M;
  int maxP = INT_MIN;
  cin>>N>>M;
  vector<vector<int> > adjList(N);
  vector<int> distances(N,0);
  vector<bool> visited(N,false);
  for(int i=0;i<M;i++){
    pair<int,int> e;
    cin>>e.first>>e.second;
    adjList[e.first-1].push_back(e.second-1);
  }
  // for(int i=0;i<N-1;i++){
  //   for(int j=0;j<M;j++){
  //     pair<int,int> e = edges[j];
  //     int src = e.first;
  //     int dist = e.second;
  //     distances[dist-1] = max(distances[dist-1],1+distances[src-1]);
  //   }
  // }
  for(int i=0;i<N;i++){
    if(!visited[i])
      traverse(distances,adjList,visited,i);
  }
  for(int i=0;i<N;i++){
    //
      maxP = max(maxP,distances[i]);


  }

  cout<<maxP;



  return 0;
}
