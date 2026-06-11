#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>

using lli=long long;

int main(){
  int N;
  std::cin >> N;

  std::vector<std::tuple<lli, lli>> Di_arr(N);
  for(int i = 0; i < N; i++){
    lli tmp;
    std::cin >> tmp;
    Di_arr[i] = std::make_tuple(tmp, i+1);
  }

  std::sort(Di_arr.begin(), Di_arr.end(), [](const std::tuple<lli, lli>& l, const std::tuple<lli, lli>& r){ return std::get<0>(l) > std::get<0>(r); });
  std::vector<lli> D_arr(N), re_arr(N);
  for(int i = 0; i < N; i++){
    D_arr[i] = std::get<0>(Di_arr[i]);
    re_arr[i] = std::get<1>(Di_arr[i]);
  }

  std::vector<std::tuple<lli, lli>> node_info(N, std::make_tuple(1, 0));

  bool fail=false;
  std::vector<std::tuple<lli, lli>> edges;
  for(int i = 0; i < N-1; i++){
    lli nnodes, length;
    std::tie(nnodes, length) = node_info[i];
    lli parent_d = D_arr[i]-(N-nnodes)+nnodes;
    auto parent_it = std::lower_bound(D_arr.rbegin(), D_arr.rend(), parent_d);
    if(parent_it == D_arr.rend() || *parent_it != parent_d){
      fail=true;
      break;
    }
    lli parent = std::distance(D_arr.begin(), parent_it.base()-1);
    edges.push_back(std::make_tuple(i, parent));
    std::get<0>(node_info[parent]) += nnodes;
    std::get<1>(node_info[parent]) += length+nnodes;
  }
  if(std::get<1>(node_info[N-1]) != D_arr[N-1]) fail=true;

  if(fail){
    std::cout << -1 << std::endl;
  }else{
    for(auto&& it: edges){
      std::cout << re_arr[std::get<0>(it)] << " " << re_arr[std::get<1>(it)] << "\n";
    }
  }

  return 0;
}

