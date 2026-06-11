#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>

int main(){

  // read problem
  long long int N, tmp;
  scanf("%lld", &N);
  
  std::vector<std::vector<long long int> > a(N);
  for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j < N; j++){
      scanf("%lld", &tmp);
      a[i].push_back(tmp);
    }
  }

  // calculate group score
  std::vector<long long int> group_tmp(N), group_score;
  long long int n_member, score_tmp;

  for(long long int S = 0; S < (1<<N); S++){
    // make group
    n_member = 0;
    for(long long int i = 0; i < N; i++){
      if((S>>i) & 1){
        group_tmp[n_member] = i;
        n_member++;
      }
    }
    // calculate score
    score_tmp = 0;
    for(long long int i = 0; i < n_member; i++){
      for(long long int j = i+1; j < n_member; j++){
        score_tmp += a[group_tmp[i]][group_tmp[j]];
      }
    }

    group_score.push_back(score_tmp);
  }

  long long int x, y, subS;
  // solve problem
  for(long long int n = 2; n <= N; n++){
    for(long long int S = (1<<n)-1; S < (1<<N); x = S&(-S), y = S+x, S = (((S & ~y) / x) >> 1) | y /*S = next_combination(S)*/){

      // make group
      n_member = 0;
      for(long long int i = 0; i < N; i++){
        if((S>>i) & 1){
          group_tmp[n_member] = i;
          n_member++;
        }
      }

      /*std::cerr << "n_member = " << n_member << std::endl;
      std::cerr << "S: ";
      for(long long int i = 0; i < N; i++){
        tmp = (S>>i)&1;
        std::cerr << tmp << " ";
      }std::cerr << std::endl;*/

      for(long long int i = 0; i < (1<<(n_member-1)); i++){
        // make subgroup
        subS = 0;
        for(long long int j = 0; j < n_member; j++){
          if((i>>j)& 1){
            subS += (1<< group_tmp[j]);
          }
        }

       /* std::cerr << "subS: " << std::endl;
        for(long long int i = 0; i < N; i++){
          tmp = (subS>>i)&1;
          std::cerr << tmp << " ";
        }std::cerr << std::endl;*/
        
        // update group_score[S]
        group_score[S] = std::max(group_score[S], group_score[S-subS] + group_score[subS]);
      }
    }
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << group_score[(1<<N)-1] << std::endl;

  return 0;
}